#include "Camera.h"

Camera::Camera(const int width, const int height, const glm::vec3& position)
{
	startPosition = position;
	freeCamera = false;
	Set(width, height, position);
}

void Camera::Set(const int width, const int height, const glm::vec3& position)
{
	this->isPerspective = true;
	this->yaw = YAW;
	this->pitch = PITCH;

	this->FoVy = FOV;
	this->width = width;
	this->height = height;
	this->zNear = zNEAR;
	this->zFar = zFAR;

	this->worldUp = glm::vec3(0, 1, 0);
	this->position = position;

	lastX = width / 2.0f;
	lastY = height / 2.0f;
	bFirstMouseMove = true;

	UpdateCameraVectors();
}

void Camera::SetFreeCamera(const bool& value)
{
	freeCamera = value;
}

void Camera::Reset(const int width, const int height)
{
	Set(width, height, startPosition);
}

void Camera::Reshape(int windowWidth, int windowHeight)
{
	width = windowWidth;
	height = windowHeight;

	// define the viewport transformation
	glViewport(0, 0, windowWidth, windowHeight);
}

const glm::mat4 Camera::GetViewMatrix() const
{
	// Returns the View Matrix
	return glm::lookAt(position, position + forward, up);
}

const glm::mat4 Camera::GetProjectionMatrix() const
{
	glm::mat4 Proj = glm::mat4(1);
	if (isPerspective) {
		float aspectRatio = ((float)(width)) / height;
		Proj = glm::perspective(glm::radians(FoVy), aspectRatio, zNear, zFar);
	}
	else {
		float scaleFactor = 2000.f;
		Proj = glm::ortho<float>(
			-width / scaleFactor, width / scaleFactor,
			-height / scaleFactor, height / scaleFactor, -zFar, zFar);
	}
	return Proj;
}

const glm::vec3 Camera::GetPosition() const
{
	//std::cout << position.x << " " << position.y << " " << position.z << std::endl;
	return position;
}

void Camera::ProcessKeyboard(ECameraMovementType direction, float deltaTime)
{
	float velocity = (float)(cameraSpeedFactor * deltaTime);
	switch (direction) {
	case ECameraMovementType::FORWARD:
		position += forward * velocity;
		break;
	case ECameraMovementType::BACKWARD:
		position -= forward * velocity;
		break;
	case ECameraMovementType::LEFT:
		position -= right * velocity;
		break;
	case ECameraMovementType::RIGHT:
		position += right * velocity;
		break;
	case ECameraMovementType::UP:
		position += up * velocity;
		break;
	case ECameraMovementType::DOWN:
		position -= up * velocity;
		break;
	}
	if (!freeCamera)
	{
		if (this->position.z > 5.2f || fmod(this->position.z, 13.f) < -5.5f && fmod(this->position.z, 13.f) > -7.5f)
		{
			if (this->position.z > 5.4f)
			{
				this->position.y = 0.9f;
				if (this->position.z > 6.6f)
					this->position.z = 6.6f;
				if (this->position.x < -3.5f)
					this->position.x = -3.5f;
				else if (this->position.x > 2.6f)
					this->position.x = 2.6f;
			}
			else if (this->position.z < 5.4f && this->position.z > 5.2f && (this->position.x > 0.35f || this->position.x < -1.35f))
			{
				this->position.z = 5.4f;
				this->position.y = 0.9f;
				if (this->position.x < -3.35f)
					this->position.x = -3.35f;
				else if (this->position.x > 2.45f)
					this->position.x = 2.45f;
			}
			else if (fmod(this->position.z, 13.f) > -5.65f && ((this->position.x > 0.35f && this->position.x < 4.65f) || (this->position.x < -1.35f && this->position.x > -5.65f)))
			{
				int k = this->position.z / 13.f;
				this->position.z = -5.65f + k * 13.f;
				this->position.y = 0.65f;
			}
			else if (fmod(this->position.z, 13.f) < -7.35f && ((this->position.x > 0.35f && this->position.x < 4.65f) || (this->position.x < -1.35f && this->position.x > -5.65f)))
			{
				int k = this->position.z / 13.f;
				this->position.z = -7.35f + k * 13.f;
				this->position.y = 0.65f;
			}
			else this->position.y = 0.65;
		}
		else
		{
			this->position.y = 0.65f;
			if (this->position.x > 0.35f && this->position.x < 4.65f)
			{
				if (abs(this->position.x - 4.65f) < abs(this->position.x - 0.35f))
					this->position.x = 4.65f;
				else this->position.x = 0.35f;
			}
			else if (this->position.x < -1.35f && this->position.x > -5.65f)
			{
				if (abs(this->position.x + 1.35f) < abs(this->position.x + 5.65f))
					this->position.x = -1.35f;
				else this->position.x = -5.65f;
			}
		}
		if (this->position.x < -7.35f)
			this->position.x = -7.35f;
		else if (this->position.x > 6.35f)
			this->position.x = 6.35f;
		if (this->position.z < -59.2f)
			this->position.z = -59.2f;
	}
}

void Camera::MouseControl(float xPos, float yPos)
{
	if (bFirstMouseMove) {
		lastX = xPos;
		lastY = yPos;
		bFirstMouseMove = false;
	}

	float xChange = xPos - lastX;
	float yChange = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	if (fabs(xChange) <= 1e-6 && fabs(yChange) <= 1e-6) {
		return;
	}
	xChange *= mouseSensitivity;
	yChange *= mouseSensitivity;

	ProcessMouseMovement(xChange, yChange);
}

void Camera::ProcessMouseScroll(float yOffset)
{
	if (FoVy >= 1.0f && FoVy <= 90.0f) {
		FoVy -= yOffset;
	}
	if (FoVy <= 1.0f)
		FoVy = 1.0f;
	if (FoVy >= 90.0f)
		FoVy = 90.0f;
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset, bool constrainPitch)
{
	yaw += xOffset;
	pitch += yOffset;

	//std::cout << "yaw = " << yaw << std::endl;
	//std::cout << "pitch = " << pitch << std::endl;

	// Avem grijã sã nu ne dãm peste cap
	if (constrainPitch) {
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	// Se modificã vectorii camerei pe baza unghiurilor Euler
	UpdateCameraVectors();
}

void Camera::UpdateCameraVectors()
{
	// Calculate the new forward vector
	this->forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	this->forward.y = sin(glm::radians(pitch));
	this->forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	this->forward = glm::normalize(this->forward);
	// Also re-calculate the Right and Up vector
	right = glm::normalize(glm::cross(forward, worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, forward));
}
