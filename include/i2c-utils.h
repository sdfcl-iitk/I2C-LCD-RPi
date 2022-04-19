#pragma once

extern "C" {
    #include <stdint.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
    #include <sys/ioctl.h>
}

class I2CUtils {
    private:
    int bus;

    public:
    I2CUtils() {
        bus = open("/dev/i2c-1", O_RDWR);
    }

    ~I2CUtils() {
        close(bus);
    }

    bool read_byte(const uint8_t dev_addr, uint8_t &data) const {
        ioctl(bus, I2C_SLAVE, dev_addr);
        data = i2c_smbus_read_byte(bus);
        return data != 0xFF;
    }

    bool write_byte(const uint8_t dev_addr, uint8_t &data) const {
        ioctl(bus, I2C_SLAVE, dev_addr);
        uint8_t ret = i2c_smbus_write_byte(bus, data);
        return ret != 0xFF;
    }

    bool read_reg_byte(const uint8_t dev_addr, const uint8_t reg, uint8_t &data) const {
        ioctl(bus, I2C_SLAVE, dev_addr);
        data = i2c_smbus_read_byte_data(bus, reg);
        return data != 0xFF;
    }

    bool write_reg_byte(const uint8_t dev_addr, const uint8_t reg, uint8_t &data) const {
        ioctl(bus, I2C_SLAVE, dev_addr);
        uint8_t ret = i2c_smbus_write_byte_data(bus, reg, data);
        return ret != 0xFF;
    }

    bool read_reg_block(const uint8_t dev_addr, const uint8_t reg, const uint8_t length, uint8_t *data) const {
        ioctl(bus, I2C_SLAVE, dev_addr);
        uint8_t ret = i2c_smbus_read_i2c_block_data(bus, reg, length, data);
        return ret == length;
    }

    bool write_reg_block(const uint8_t dev_addr, const uint8_t reg, const uint8_t length, uint8_t *data) const {
        ioctl(bus, I2C_SLAVE, dev_addr);
        uint8_t ret = i2c_smbus_write_i2c_block_data(bus, reg, length, data);
        return ret != 0xFF;
    }
};