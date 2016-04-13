/*=================================================================================================
   Copyright (c) 2016 Joel de Guzman

   Licensed under a Creative Commons Attribution-ShareAlike 4.0 International.
   http://creativecommons.org/licenses/by-sa/4.0/
=================================================================================================*/
#if !defined(PHOTON_GUI_LIB_WIDGET_TILE_APRIL_13_2016)
#define PHOTON_GUI_LIB_WIDGET_TILE_APRIL_13_2016

#include <photon/widget/widget.hpp>
#include <memory>

namespace photon
{
   ////////////////////////////////////////////////////////////////////////////////////////////////
   // Vertical Tiles
   ////////////////////////////////////////////////////////////////////////////////////////////////
   class vtile_widget : public composite
   {
   public:

      vtile_widget() {}
      ~vtile_widget() {}

      virtual rect         limits() const;
      virtual void         layout(rect const& b);
      virtual rect         bounds_of(std::size_t index) const;

   private:

      std::vector<float>   _tiles;
      float                _left;
      float                _right;
   };

   template <typename... W>
   inline widget_ptr vtile(W const&... elements)
   {
      auto p = new vtile_widget{};
      std::vector<widget_ptr> v = { elements... };
      std::swap(v, p->elements());
      return widget_ptr{ p };
   }
}

#endif