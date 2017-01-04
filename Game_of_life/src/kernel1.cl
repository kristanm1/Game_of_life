__kernel void simulateOne(	__global float *area,
							__global float *new_area,
							int height,
							int width				) {

	int non;
	for(int row = get_global_id(0); row < height; row += get_local_size(0)) {
		for(int col = get_global_id(1); col < width; col += get_local_size(1)) {
			
			non = 0;
			for(int i = -2; i < 3; i++) {
				for(int j = -2; j < 3; j++) {
					if(!(i == 0 && j == 0)) {
						if((row + i) < height && (row + i) >= 0 && (col + j) < width && (col + j) >= 0) {
							if(area[(row + i)*width + col + j] > 0) {
								non += 1;
							}
						}
					}
				}
			}
			
			int area_t = area[row*width + col];
			if(area_t == 0) {
				if(non == 4) {
					new_area[row*width + col] = 1;
				}
				else {
					new_area[row*width + col] = 0;
				}
			}
			else if(area_t == 1){
				if(non == 3) {
					new_area[row*width + col] = 1;
				}
				else {
					new_area[row*width + col] = 0;
				}
			}

		}
	}
}