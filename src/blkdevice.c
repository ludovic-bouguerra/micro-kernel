#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct blkdevice_file_t{
  char *name;
} *blkdevice_file;

typedef struct blkdevice_partition_t{
  char* name;
  char* type;
} *blkdevice_partition;

typedef struct blkdevice_device_t{
  int partitions_count;
  blkdevice_partition* partitions;
} *blkdevice_device;

int blkdevice_register_drive(blkdevice_device device){

}

int list_devices(blkdevice_device** devices){

  *devices = malloc(1*sizeof(blkdevice_device));
  (*devices)[0] = malloc(sizeof(struct blkdevice_device_t));

  (*devices)[0]->partitions = malloc(1*sizeof(blkdevice_partition));
  (*devices)[0]->partitions[0] = malloc(sizeof(struct blkdevice_partition_t));
  (*devices)[0]->partitions[0]->name = "Hello";
  (*devices)[0]->partitions[0]->type = "vfat";
  return 1;
}

int main(int argc, char** argv){
  blkdevice_device* devices;

  list_devices(&devices);


  printf ("Reading Fat32 %d %s %s \n", devices[0]->partitions_count, devices[0]->partitions[0]->name, devices[0]->partitions[0]->type);
  return 0;
}
