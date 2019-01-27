using System;
using System.Threading.Tasks;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using RuntimeComponent1;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace App1
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    // ReSharper disable once RedundantExtendsListEntry
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            InitializeComponent();
        }

        private void GoTestFunctionClick(object sender, RoutedEventArgs e)
        {
            int a = int.Parse(Argument.Text);

            GoTest goTest = new GoTest();

            int result = goTest.GoTestFunction(a);

            Result.Text = result.ToString();
        }
    }
}
