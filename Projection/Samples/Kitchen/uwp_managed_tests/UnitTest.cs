
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Microsoft.SDKSamples.Kitchen;
using Windows.Foundation;
using System.Threading;

namespace uwp_managed_tests
{
    [TestClass]
    public class OvenUnitTests
    {
        [TestMethod]
        public void oven_volume_dimensions_ctor()
        {
            Dimensions dimensions;
            dimensions.Width = 2;
            dimensions.Height = 2;
            dimensions.Depth = 2;

            var oven = new Oven(dimensions);

            Assert.AreEqual(8.0, oven.Volume, 0.01);
        }

        [TestMethod]
        public void oven_volume_default_ctor()
        {
            var oven = new Oven();
            Assert.AreEqual(0.0, oven.Volume, 0.01);
        }

        [TestMethod]
        public void oven_bake_bread()
        {
            var @event = new ManualResetEvent(false);

            var oven = new Oven();
            oven.BreadBaked += new TypedEventHandler<Oven, BreadBakedEventArgs>(
                (sender, args) =>
                {
                    Assert.AreEqual("Wheat", args.Bread.Flavor, "flavor");
                    @event.Set();
                });
            oven.BakeBread("Wheat");

            var event_fired = @event.WaitOne(1000);
            Assert.IsTrue(event_fired, "event fired");
        }

        private void Oven_BreadBaked(Oven sender, BreadBakedEventArgs args)
        {
            throw new NotImplementedException();
        }
    }
}