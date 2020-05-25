using System;
using CoreGraphics;
using Foundation;
using UIKit;
using Xamarin.HEREMaps.iOS;

namespace HereMapsTestApp
{
    public class VehicleMapMarker : NMAMapMarker
    {
        public VehicleMapMarker(NMAGeoCoordinates coordinates, string vehicleName) : base(coordinates)
        {
            VehicleImageContext imageContext = GenerateMarkerImageWithText(vehicleName);
            Icon = NMAImage.ImageWithUIImage(imageContext.image);
            // place the blue dot of the marker image on the correct location on the map
            AnchorOffset = imageContext.anchorOffset;
        }

        private VehicleImageContext GenerateMarkerImageWithText(string vehicleName)
        {
            NSString markerText = new NSString(vehicleName);
            UIStringAttributes attributes = new UIStringAttributes { Font = UIFont.FromName("Arial", 16), ForegroundColor = UIColor.White };
            CGSize sizeOfMarkerText = markerText.GetSizeUsingAttributes(attributes);

            NSAttributedString markerString = new NSAttributedString(vehicleName, attributes);

            // Calculate element sizes depending on text and text attributes like font and font size
            float labelHeight = (float)Math.Ceiling(sizeOfMarkerText.Height * 2.0);
            float labelWidth = (float)Math.Ceiling(sizeOfMarkerText.Width);
            float labelEndSize = labelHeight;
            float gpsPointSize = 10.0f;
            float distanceBetweenLabelAndPoint = 10;

            CGSize imageSize = new CGSize(labelWidth + (labelEndSize), labelHeight + distanceBetweenLabelAndPoint + gpsPointSize);

            UIGraphicsImageRenderer renderer = new UIGraphicsImageRenderer(imageSize);
            UIImage image = renderer.CreateImage((context) =>
            {
                // Color Declarations
                UIColor blueZodiacColor = new UIColor(15.0f / 255f, 42.0f / 255f, 72.0f / 255f, 1.0f);

                // Draw label rectangle
                nfloat rectX = labelEndSize / 2.0f;
                nfloat rectY = 0;
                nfloat rectWidth = labelWidth;
                nfloat rectHeight = labelHeight;
                CGRect rectangleSize = new CGRect(rectX, rectY, rectWidth, rectHeight);
                UIBezierPath rectanglePath = UIBezierPath.FromRect(rectangleSize);
                blueZodiacColor.SetFill();
                rectanglePath.Fill();

                // Draw text
                nfloat textX = rectangleSize.Location.X;
                nfloat textY = rectangleSize.Location.Y + (rectangleSize.Size.Height / 4.0f);
                nfloat textWidth = labelWidth;
                nfloat textHeight = labelHeight;
                markerString.DrawString(new CGRect(textX, textY, textWidth, textHeight));

                // Draw label end left
                nfloat endLeftX = 0;
                nfloat endLeftY = 0;
                CGRect endcupLeftRect = new CGRect(endLeftX, endLeftY, labelEndSize, labelEndSize);
                UIBezierPath endcupLeftPath = new UIBezierPath();
                endcupLeftPath.AddArc(new CGPoint(endcupLeftRect.GetMidX(), endcupLeftRect.GetMidY()), endcupLeftRect.Size.Width / 2, (nfloat)(90.0d * Math.PI / 180.0d), (nfloat)(-90.0d * Math.PI / 180.0d), true);
                endcupLeftPath.AddLineTo(new CGPoint(endcupLeftRect.GetMidX(), endcupLeftRect.GetMidY()));
                endcupLeftPath.ClosePath();

                blueZodiacColor.SetFill();
                endcupLeftPath.Fill();

                // Draw label end right
                nfloat endRightX = rectangleSize.Size.Width;
                nfloat endRightY = 0;
                CGRect endcupRightRect = new CGRect(endRightX, endRightY, labelEndSize, labelEndSize);
                UIBezierPath endcupRightPath = new UIBezierPath();
                endcupRightPath.AddArc(new CGPoint(endcupRightRect.GetMidX(), endcupRightRect.GetMidY()), endcupRightRect.Size.Width / 2, (nfloat)(270d * Math.PI / 180d), (nfloat)(90d * Math.PI / 180d), true);
                endcupRightPath.AddLineTo(new CGPoint(endcupRightRect.GetMidX(), endcupRightRect.GetMidY()));
                endcupRightPath.ClosePath();

                blueZodiacColor.SetFill();
                endcupRightPath.Fill();

                // Draw GPS point
                nfloat pointX = (nfloat)((imageSize.Width / 2.0) - (gpsPointSize / 2.0));
                nfloat pointY = labelHeight + distanceBetweenLabelAndPoint;
                UIBezierPath gpsPointPath = UIBezierPath.FromOval(new CGRect(pointX, pointY, gpsPointSize, gpsPointSize));
                blueZodiacColor.SetFill();
                gpsPointPath.Fill();
            });

            // Create vehicle image context and set image
            VehicleImageContext vehicleImageContext = new VehicleImageContext();
            vehicleImageContext.image = image;
            // Calculate anchor offset to place the image correctly on the map
            vehicleImageContext.anchorOffset = new CGPoint(0.0, -((imageSize.Height / 2.0) - (gpsPointSize / 2.0)));

            return vehicleImageContext;
        }
    }
}
