using CoreGraphics;
using UIKit;

namespace HereMapsTestApp
{
    public class VehicleImageContext
    {
        public CGPoint anchorOffset { get; set; }
        public UIImage image { get; set; }

        public VehicleImageContext()
        {
        }

        public VehicleImageContext(UIImage image, CGPoint anchorOffset)
        {
            this.anchorOffset = anchorOffset;
            this.image = image;
        }
    }
}
