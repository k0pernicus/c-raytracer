#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "vec3d.h"
#include "ray.h"
#include "objects/object.h"
#include "objects/sphere.h"

// HEIGHT defines the length of the image to output
const int HEIGHT = 400;
// WIDTH defines the width of the image to output
const int WIDTH = 800;

void to_stdout(const ppm_buffer data)
{
    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    int index = 0;
    while (index < HEIGHT)
    {
        for (int c_column = 0; c_column < WIDTH; c_column++)
        {
            printf("%d ", data[c_column + index * WIDTH]);
        }
        printf("\n");
        index++;
    }
}

void ppm_to_file(const ppm_buffer buffer, const char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("cannot create file with name %s\n", filename);
        return;
    }
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    int index = 0;
    while (index < HEIGHT)
    {
        for (int c_column = 0; c_column < 3 * WIDTH; c_column++)
        {
            if (c_column < ((3 * WIDTH) - 1))
            {
                fprintf(fp, "%d ", buffer[c_column + (index * 3 * WIDTH)]);
            }
            else
            {
                fprintf(fp, "%d", buffer[c_column + (index * 3 * WIDTH)]);
            }
        }
        fprintf(fp, "\n");
        index++;
    }
    fclose(fp);
}

ppm_buffer generate_gradient_data_from(const vec3d *camera)
{
    ppm_buffer data = (ppm_buffer)malloc(HEIGHT * WIDTH * 3 * sizeof(int));
    long unsigned int c_index = 0;
    vec3d lower_left_corner = {-2.0, -1.0, -1.0};
    vec3d horizontal = {4.0, 0.0, 0.0};
    vec3d vertical = {0.0, 2.0, 0.0};
    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            const vec3d u_v = vec3d_mul_scalar(&horizontal, (double)i / (double)WIDTH);
            const vec3d v_v = vec3d_mul_scalar(&vertical, (double)j / (double)HEIGHT);
            const vec3d tmp_u_v = vec3d_add(&u_v, &v_v);
            const vec3d tmp_lower_u_v = vec3d_add(&lower_left_corner, &tmp_u_v);
            const ray r = {
                camera,
                &tmp_lower_u_v,
            };
            const object sphere = new_sphere(&r);
            double t = hit_from_origin(&sphere, 0.5);
            const vec3d blended_value = get_color(&sphere, t);
            const int c_colors[3] = {(int)(255.99 * blended_value.x), (int)(255.99 * blended_value.y), (int)(255.99 * blended_value.z)};
            for (int c_color_index = 0; c_color_index < 3; c_color_index++)
            {
                data[c_index] = c_colors[c_color_index];
                c_index++;
            }
        }
    }
    return data;
}

ppm_buffer generate_fake_data()
{
    ppm_buffer data = (ppm_buffer)malloc(HEIGHT * WIDTH * 3 * sizeof(int));
    long unsigned int c_index = 0;
    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            vec3d v = {
                (float)i / (float)WIDTH,
                (float)j / (float)HEIGHT,
                0.2};
            int c_colors[3] = {(int)(255.99 * v.x), (int)(255.99 * v.y), (int)(255.99 * v.z)};
            for (int c_color_index = 0; c_color_index < 3; c_color_index++)
            {
                data[c_index] = c_colors[c_color_index];
                c_index++;
            }
        }
    }
    return data;
}
