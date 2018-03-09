using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace SerialPixelsPC
{
    public partial class Form1 : Form
    {

        static SerialPort serialPort;

        public Form1()
        {
            InitializeComponent();
        }

        public void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        //Button to get COM ports and add them to comboBox1
        private void button1_Click(object sender, EventArgs e)
        {


            //Clear all current items in the combobox list
            comboBox1.Items.Clear();

            //Get an array of ports and assign it to ports
            string[] ports = SerialPort.GetPortNames();

            //Go through each port in ports and add it to the Items in comboBox1
            foreach (string port in ports)
            {
                comboBox1.Items.Add(port);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //When the button is pressed, check the colour selected by the colorDialog which pops up
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                //Set bytes R, G and B equal to the selected colour's Red, Green and Blue values
                byte R = colorDialog1.Color.R;
                byte G = colorDialog1.Color.G;
                byte B = colorDialog1.Color.B;

                label1.Text = String.Format("R,G,B = {0}, {1}, {2}", R, G, B);
                
                // Create a new SerialPort object with default settings
                serialPort = new SerialPort(Convert.ToString(comboBox1.Text));

                // Set the baudrate (the default of 9600 is a tad slow)
                serialPort.BaudRate = 115200;

                //Open the port
                serialPort.Open();
                //Send "<R,G,B>".  Data are only used by the Trinket if enclosed between square brackets. 
                serialPort.WriteLine(Convert.ToString(R) + "," + Convert.ToString(G) + "," + Convert.ToString(B));
                //Close the port
                serialPort.Close();
            }
        }

        
    }
}
