#include <stdio.h>
#include "messages/encoder.h"
#include "messages/imu.h"
#include "messages/power.h"
#include "messages/receive.h"

int main(void) {
    PacketInfo test_encoder, test_imu, test_receive, test_power;
    test_imu = transform_imu_data(0x6,0x6,0x6);
    test_encoder = transform_encoder_data(0x69, 0x420);
    test_receive = transform_receive_data(0x666, 0x911);
    test_power = transform_power_data(0x69);

    printf("IMU Data: \n");
    for (int i = 0; i < MAX_DATA_SIZE; i++){
       printf("%X\n",test_imu.data[i]);
    }
    printf("\n");
    
    printf("Encoder Data: \n");
    for (int i = 0; i < MAX_DATA_SIZE; i++){
       printf("%X\n",test_encoder.data[i]);
    }
    printf("\n");

    printf("Receive Data: \n");
    for (int i = 0; i < MAX_DATA_SIZE; i++){
       printf("%X\n",test_receive.data[i]);
    }
    printf("\n");

    printf("Power Data: \n");
    for (int i = 0; i < MAX_DATA_SIZE; i++){
       printf("%X\n",test_power.data[i]);
    }
    printf("\n");    

    Packet test_encoder_packet, test_imu_packet, test_receive_packet, test_power_packet;
    test_imu_packet = info_to_packet(test_imu);
    test_encoder_packet = info_to_packet(test_encoder);
    test_receive_packet = info_to_packet(test_receive);
    test_power_packet = info_to_packet(test_power);

    printf("\nIMU Packet:|%X|%X|%X|\n", test_imu_packet.ff_bytes, test_imu_packet.sf_bytes, test_imu_packet.lf_bytes);
    printf("Encoder Packet:|%X|%X|%X|\n", test_encoder_packet.ff_bytes, test_encoder_packet.sf_bytes, test_encoder_packet.lf_bytes);
    printf("Receive Packet:|%X|%X|%X|\n", test_receive_packet.ff_bytes, test_receive_packet.sf_bytes, test_receive_packet.lf_bytes);
    printf("Power Packet: |%X|%X|%X|\n", test_power_packet.ff_bytes, test_power_packet.sf_bytes, test_power_packet.lf_bytes);
    return 0;
}