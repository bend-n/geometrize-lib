#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <vector>

#include "rgba.h"

namespace geometrize {

/**
 * @brief The Bitmap class is a helper class for working with bitmap data.
 * @author Sam Twidale (https://samcodes.co.uk/)
 */
class Bitmap {
  public:
    /**
     * @brief Bitmap Creates a new bitmap.
     * @param width The width of the bitmap.
     * @param height The height of the bitmap.
     * @param color The starting color of the bitmap (RGBA format).
     */
    Bitmap(std::uint32_t width, std::uint32_t height, geometrize::rgba color);
    /**
     * @brief Bitmap Creates a new bitmap from the supplied byte data.
     * @param width The width of the bitmap.
     * @param height The height of the bitmap.
     * @param data The byte data to fill the bitmap with, must be width * height
     * * depth (4) long.
     */
    Bitmap(std::uint32_t width, std::uint32_t height, std::uint8_t *data);

    ~Bitmap() { free(m_data); };
    Bitmap &operator=(const geometrize::Bitmap &) = default;
    Bitmap(const geometrize::Bitmap &) = default;

    /**
     * @brief getWidth Gets the width of the bitmap.
     */
    std::uint32_t getWidth() const;

    /**
     * @brief getHeight Gets the height of the bitmap.
     */
    std::uint32_t getHeight() const;

    std::size_t size() const;
    std::size_t pixels() const;

    /**
     * @brief getPixel Gets a pixel color value.
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return The pixel RGBA color value.
     */
    geometrize::rgba getPixel(std::uint32_t x, std::uint32_t y) const;

    /**
     * @brief setPixel Sets a pixel color value.
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @param color The pixel RGBA color value.
     */
    void setPixel(std::uint32_t x, std::uint32_t y, geometrize::rgba color);

    /**
     * @brief fill Fills the bitmap with the given color.
     * @param color The color to fill the bitmap with.
     */
    void fill(geometrize::rgba color);

  public:
    std::uint32_t m_width;  ///< The width of the bitmap.
    std::uint32_t m_height; ///< The height of the bitmap.
    uint8_t *m_data;        ///< The bitmap data.
};

} // namespace geometrize
