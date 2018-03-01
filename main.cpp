#include <SDL2/SDL.h>

#define VK_USE_PLATFORM_XLIB_KHR
#include <vulkan/vulkan.h>

#include <stdio.h>

VkInstance m_instance;

int main(int argc, char* argv[]) {
	printf("Start\n");

	VkApplicationInfo appInfo;
	VkInstanceCreateInfo instanceCreateInfo;

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pNext = nullptr;
	appInfo.pApplicationName = "Testing";
	appInfo.applicationVersion = 1;
	appInfo.pEngineName = "Hot Doggin";
	appInfo.engineVersion = 2;
	appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);

	instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pNext = nullptr;
	instanceCreateInfo.flags = 0;
	instanceCreateInfo.pApplicationInfo = &appInfo;
	instanceCreateInfo.enabledLayerCount = 0;
	instanceCreateInfo.ppEnabledLayerNames = nullptr;
	instanceCreateInfo.enabledExtensionCount = 0;
	instanceCreateInfo.ppEnabledExtensionNames = nullptr;

	printf("Setup done... trying\n");

	VkResult result = vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance);

	printf("Success? %i = %i\n", result, VK_SUCCESS);

	vkDestroyInstance(m_instance, nullptr);

	return 0;
}
