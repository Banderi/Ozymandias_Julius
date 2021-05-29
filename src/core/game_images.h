#ifndef GAME_IMAGES_H
#define GAME_IMAGES_H

#include "core/image.h"
#include "core/image_collection.h"

static const size_t NAME_SIZE = 32;

class game_images {
private:
    static const size_t TMP_DATA_SIZE = 16000000;

    bool editor;
    bool fonts_enabled;
    int current_climate;
    int font_base_offset;
    int terrain_ph_offset;

    image_collection *ph_expansion;
    image_collection *ph_sprmain;
    image_collection *ph_unloaded;
    image_collection *main;
    image_collection *ph_terrain;

    image_collection *ph_sprmain2;
    image_collection *ph_sprambient;
    image_collection *ph_mastaba;

    image_collection *enemy;
    image_collection *empire;
    image_collection *font;

    color_t *tmp_image_data;

public:
    game_images();
    game_images(game_images const&) = delete;             // Copy construct
    game_images(game_images&&) = delete;                  // Move construct
    game_images& operator=(game_images const&) = delete;  // Copy assign
    game_images& operator=(game_images &&) = delete;      // Move assign
    ~game_images();

    // singleton
    static game_images& get() {
        static game_images instance;
        return instance;
    }

    // load images from files
    int load_main(int climate_id, int is_editor, int force_reload);
    int load_fonts(encoding_type encoding);
    int load_enemy(int enemy_id);

    // getting images
    int get_image_id(int group);
    const image *get_image(int id, int mode = 0);
    const image *image_letter(int letter_id);
    const image *image_get_enemy(int id);
    const color_t *image_data(int id);
    const color_t *image_data_letter(int letter_id);
    const color_t *image_data_enemy(int id);
    int image_groupid_translation(int *table, int group);
    const color_t *load_external_data(const image *img);

    // getters & setters
    int get_current_climate() const;
    void set_current_climate(int new_climate);
    bool is_editor() const;
    void set_editor(bool new_editor);
    bool is_fonts_enabled() const;
    void set_fonts_enabled(bool new_fonts_enabled);
    int get_font_base_offset() const;
    void set_font_base_offset(int new_font_base_offset);
    int get_terrain_ph_offset() const;
    void set_terrain_ph_offset(int new_terrain_ph_offset);
};

// TODO: temporary functions to be removed
int image_id_from_group(int group);
const image *image_get(int id, int mode = 0);
const image *image_letter(int letter_id);
const image *image_get_enemy(int id);
const color_t *image_data(int id);
const color_t *image_data_letter(int letter_id);
const color_t *image_data_enemy(int id);

#endif //GAME_IMAGES_H
