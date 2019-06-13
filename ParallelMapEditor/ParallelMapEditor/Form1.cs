using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ParallelMapEditor
{
    public partial class Form1 : Form
    {
        private MainMenu mainMenu;
        private Bitmap[][] tileSet;

        public int TileSize = 0;
        public bool MapLoaded = false;

        public Form1()
        {
            InitializeComponent();
            mainMenu = new MainMenu();
            MenuItem File = mainMenu.MenuItems.Add("&File");
            File.MenuItems.Add(new MenuItem("&Load Map...", new EventHandler(this.LoadMapClick)));
            File.MenuItems.Add(new MenuItem("&Save Map..."));
            File.MenuItems.Add(new MenuItem("&Save Map As..."));

            MenuItem About = mainMenu.MenuItems.Add("&About");
            About.MenuItems.Add(new MenuItem("&About", new EventHandler(this.About_Click)));
            this.Menu = mainMenu;
        }

        private void Label1_Click(object sender, EventArgs e) {}

        private void LoadMapClick(object sender, EventArgs e)
        {
            Stream stream;
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "ptm files (*.ptm)|*.ptm";
            save.RestoreDirectory = true;
            string path = Path.Combine(Application.StartupPath, "Maps");
            if (!Directory.Exists(path))
                Directory.CreateDirectory(path);
            save.InitialDirectory = path;

            if (save.ShowDialog() == DialogResult.OK)
            {
                if ((stream = save.OpenFile()) != null)
                {
                    stream.Close();
                    MapLoaded = true;
                }
            }
        }

        private void About_Click(object sender, EventArgs e) {
            AboutBox aboutBox = new AboutBox();
            aboutBox.Show();
        }

        private void LoadTileset_Click(object sender, EventArgs e)
        {
            ErrorProvider.Clear();
            if (TileSize != 0)
            {

                OpenFileDialog open = new OpenFileDialog();
                string path = Path.Combine(Application.StartupPath, "Tileset");
                if (!Directory.Exists(path))
                    Directory.CreateDirectory(path);

                open.InitialDirectory = path;
                open.Filter = "Image Files(*.png, *.jpg; *.jpeg; *.gif; *.bmp)|*.png; *.jpg; *.jpeg; *.gif; *.bmp";
                if (open.ShowDialog() == DialogResult.OK)
                {
                    Bitmap tileset = new Bitmap(open.FileName);
                    TilesetBox.Image = tileset;
                    int width = tileset.Width;
                    int height = tileset.Height;
                }
            }
            else
            {
                ErrorProvider.SetError(LoadTileset, "You have not entered a valid tile size!");
            }
        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            ErrorProvider.Clear();
            try
            {
                string text = textBox1.Text;
                TileSize = Int32.Parse(text);
            }
            catch(FormatException)
            {
                ErrorProvider.SetError(textBox1, "You have not entered a valid integer value!");
            }
        }
    }
}
