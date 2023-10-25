#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include<iostream>
#include<complex>
using namespace std;

const int WIDTH = 1920;
const int HEIGHT = 1080;
double mandelbrot(complex<double> c) {
	complex<double> z;
	double counter = 0;
	while (abs(z) < 2 && counter < 80) {
		z = z * z + c;
		counter += 1;


	}
	return counter;
};

int main() {
	al_init();
	al_init_primitives_addon();
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);

	double zoom = 3000;

	// variables
	complex <double> c;
	int num = 0;
	al_lock_bitmap(al_get_target_bitmap(),al_get_display_format(display), al_get_display_flags(display));
	for (double i = -2; i< 2; i+=(1 / zoom))
		for (double j = -2; j < 2; j+= (1 / zoom)) {
			if (i * zoom + 3700 > 0 && j * zoom-400 > 0 && i * zoom + 3700 < WIDTH && j * zoom-400 < HEIGHT) {
				c = complex<double>(i, j);
				num = mandelbrot(c);

				al_put_pixel(i * zoom + 3700, j * zoom-400, al_map_rgb(num / 3, num * num, num * num));
			}
			//cout << "num is " << num << " at " << i*150 << " " << j*150 << endl;
			
		}
	al_unlock_bitmap(al_get_target_bitmap());
	al_flip_display();
	system("pause");
	al_destroy_display(display);



}