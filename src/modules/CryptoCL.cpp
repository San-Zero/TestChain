//
// Created by let02 on 2022/1/6.
//
#include "CryptoCL.h"

static char *source_str;
static size_t source_size;

Crypto::Crypto(const uint32_t platform_id, const uint32_t device_id) {
    std::vector<cl::Platform> platforms;
    if (platforms.empty()) {
        std::cerr << "No platforms!" << std::endl;
        exit(-1);
    }
    cl::Platform::get(&platforms);
    cl::Platform platform = platforms[platform_id];

    std::vector<cl::Device> Devices;
    if (Devices.empty()) {
        std::cerr << "No Devices!" << std::endl;
        exit(-1);
    }
    platform.getDevices(CL_DEVICE_TYPE_ALL, &Devices);
    cl::Device device = Devices[device_id];
    std::cout << "Device : " << device.getInfo<CL_DEVICE_NAME>() << std::endl;

    cl::Context context({device});

    load_source();
}



void Crypto::load_source() {
    FILE *fp;
    fp = fopen("sha256.cl", "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(-1);
    }
    char *source_str = new char[MAX_SOURCE_SIZE];
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);
}
