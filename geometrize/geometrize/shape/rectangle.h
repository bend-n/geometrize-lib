#pragma once

#include <cstdint>
#include <memory>

#include "shape.h"

namespace geometrize
{
class Model;
}

namespace geometrize
{

/**
 * @brief The Rectangle class represents a rectangle.
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class Rectangle : public Shape
{
public:
    /**
     * @brief Rectangle Creates a new rectangle.
     * @param model The model that created this shape.
     */
    Rectangle(const geometrize::Model& model);

    virtual std::shared_ptr<geometrize::Shape> clone() const;
    virtual std::vector<geometrize::Scanline> rasterize() const override;
    virtual void mutate() override;
    virtual geometrize::ShapeTypes getType() const override;
    virtual std::vector<std::int32_t> getRawShapeData() const override;
    virtual std::string getSvgShapeData() const override;

private:
    const geometrize::Model& m_model; ///< The model that produces the shape.

    std::int32_t m_x1; ///< Left coordinate.
    std::int32_t m_y1; ///< Top coordinate.
    std::int32_t m_x2; ///< Right coordinate.
    std::int32_t m_y2; ///< Bottom coordinate.
};

}
