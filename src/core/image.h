#ifndef CORE_IMAGE_H
#define CORE_IMAGE_H

#include "core/encoding.h"
#include "core/buffer.h"
#include "core/image_group.h"
#include "graphics/color.h"

#include <vector>
#include <string>
#include <algorithm>

#define IMAGE_FONT_MULTIBYTE_OFFSET 10000
#define IMAGE_FONT_MULTIBYTE_TRAD_CHINESE_MAX_CHARS 2188
#define IMAGE_FONT_MULTIBYTE_SIMP_CHINESE_MAX_CHARS 2130
#define IMAGE_FONT_MULTIBYTE_KOREAN_MAX_CHARS 2350

enum {
    IMAGE_TYPE_WITH_TRANSPARENCY = 0,
    IMAGE_TYPE_ISOMETRIC = 30,
    IMAGE_TYPE_MOD = 40
};

/**
 * @file
 * Image functions
 */

/**
 * Image metadata
 */
class image {
public:
    int width = 0;
    int height = 0;
    int num_animation_sprites = 0;
    int sprite_offset_x = 0;
    int sprite_offset_y = 0;
    int animation_can_reverse = 0;
    int animation_speed_id = 0;
    int offset_mirror = 0;

    struct {
        int type = 0;
        int is_fully_compressed = 0;
        int is_external = 0;
        int has_compressed_part = 0;
        std::string bitmap_name;
        int bmp_index = 0;
        std::vector<color_t> data;
        int offset = 0;
        int data_length = 0;
        int uncompressed_length = 0;
        size_t size = 0;
    } draw;

    image() = default;
    ~image() = default;

    void set_data(color_t *image_data, size_t size);
    const color_t *get_data() const;

    const char *get_name() const;
    void set_name(const char *filename);
    void set_name(const char *filename, size_t size);

};

extern int terrain_ph_offset;

int image_load_main(int climate_id, int is_editor, int force_reload);
int image_load_fonts(encoding_type encoding);
int image_load_enemy(int enemy_id);

int image_id_from_group(int group);

color_t to_32_bit(uint16_t c);
int convert_uncompressed(buffer *buf, int amount, color_t *dst);
int convert_compressed(buffer *buf, int amount, color_t *dst);

const image *image_get(int id, int mode = 0);
const image *image_letter(int letter_id);
const image *image_get_enemy(int id);
const color_t *image_data(int id);
const color_t *image_data_letter(int letter_id);
const color_t *image_data_enemy(int id);

#endif // CORE_IMAGE_H
