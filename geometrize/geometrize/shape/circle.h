#pragma once

#include <cstdint>
#include <memory>

#include "shape.h"

namespace geometrize
{

/**
 * @brief The Circle class represents a circle.
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class Circle : public Shape
{
public:
    /**
     * @brief Circle Creates a new circle.
     * @param xBound xBound	The x-bound of the whole canvas.
     * @param yBound yBound	The y-bound of the whole canvas.
     */
    Circle(std::int32_t xBound, std::int32_t yBound);

    virtual std::shared_ptr<geometrize::Shape> clone() const;
    virtual std::vector<geometrize::Scanline> rasterize() const override;
    virtual void mutate() override;
    virtual geometrize::shapes::ShapeTypes getType() const override;
    virtual std::vector<std::int32_t> getShapeData() const override;

private:
    const std::int32_t m_xBound; ///< The x-bound of the whole canvas.
    const std::int32_t m_yBound; ///< The y-bound of the whole canvas.

    std::int32_t m_x; ///< x-coordinate.
    std::int32_t m_y; ///< y-coordinate.
    std::int32_t m_r; ///< Radius.
};

}
