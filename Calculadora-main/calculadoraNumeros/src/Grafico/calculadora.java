package Grafico;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.ImageIcon;

public class calculadora extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtPantalla;
	

	// DECLARO VARIABLES
	float num1, num2;
	double resultado;
	String operador;
	boolean decimal = false;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					calculadora frame = new calculadora();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public void addNumber(String digito) {
		txtPantalla.setText(txtPantalla.getText()+digito);
	}

	/**
	 * Create the frame.
	 */
	public calculadora() {
		setTitle("Calculadora");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 292, 590);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);

		JPanel panel = new JPanel();
		panel.setBackground(new Color(225, 239, 255));
		panel.setBounds(0, 0, 275, 148);
		contentPane.add(panel);
		panel.setLayout(null);


		txtPantalla = new JTextField();
		txtPantalla.setBorder(null);
		txtPantalla.setBackground(new Color(225, 239, 255));
		txtPantalla.setForeground(new Color(30, 30, 30));
		txtPantalla.setFont(new Font("Ebrima", Font.BOLD, 48));
		txtPantalla.setHorizontalAlignment(SwingConstants.RIGHT);
		txtPantalla.setBounds(15, 46, 245, 59);
		panel.add(txtPantalla);
		txtPantalla.setColumns(10);

		JPanel panel_1 = new JPanel();
		panel_1.setBackground(new Color(255, 255, 255));
		panel_1.setBounds(0, 145, 275, 406);
		contentPane.add(panel_1);
		panel_1.setLayout(null);

		JButton btnMM = new JButton("+/-");
		btnMM.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btnMM.setForeground(new Color(30, 30, 30));
		btnMM.setHorizontalTextPosition(SwingConstants.CENTER);
		btnMM.setIcon(new ImageIcon("src\\imagenes\\btnazul.png"));
		btnMM.setBorder(null);
		btnMM.setRolloverIcon(new ImageIcon("src\\imagenes\\btnazul1.png"));
		btnMM.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				float cambio;
				cambio = Float.parseFloat(txtPantalla.getText());
				cambio = cambio * -1;
				txtPantalla.setText(Float.toString(cambio));
			}
		});
		btnMM.setBounds(80, 15, 50, 50);
		panel_1.add(btnMM);

		JButton btnAC = new JButton("AC");
		btnAC.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btnAC.setForeground(new Color(30, 30, 30));
		btnAC.setRolloverIcon(new ImageIcon("src\\imagenes\\btnac.png"));
		btnAC.setBorder(null);
		btnAC.setHorizontalTextPosition(SwingConstants.CENTER);
		btnAC.setIcon(new ImageIcon("src\\imagenes\\btnac1.png"));
		btnAC.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				txtPantalla.setText("");
				decimal = false;
			}
		});
		btnAC.setBounds(15, 15, 50, 50);
		panel_1.add(btnAC);

		JButton btnPorcentaje = new JButton("%");
		btnPorcentaje.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = Float.parseFloat(txtPantalla.getText());
				txtPantalla.setText("");
				operador ="%";
				decimal = false;
			}
		});
		btnPorcentaje.setRolloverIcon(new ImageIcon("src\\imagenes\\btnazul1.png"));
		btnPorcentaje.setIcon(new ImageIcon("src\\imagenes\\btnazul.png"));
		btnPorcentaje.setHorizontalTextPosition(SwingConstants.CENTER);
		btnPorcentaje.setForeground(new Color(30, 30, 30));
		btnPorcentaje.setFont(new Font("Ebrima", Font.BOLD, 20));
		btnPorcentaje.setBorder(null);
		btnPorcentaje.setBounds(145, 15, 50, 50);
		panel_1.add(btnPorcentaje);

		JButton btnBorrar = new JButton("");
		btnBorrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String texto = txtPantalla.getText().substring(0, txtPantalla.getText().length() - 1);
				txtPantalla.setText(texto);
				decimal = false;
			}
		});
		btnBorrar.setIcon(new ImageIcon("src\\imagenes\\btnborrar.PNG"));
		btnBorrar.setRolloverIcon(new ImageIcon("src\\imagenes\\btnborrar1.PNG"));
		btnBorrar.setHorizontalTextPosition(SwingConstants.CENTER);
		btnBorrar.setForeground(new Color(30, 30, 30));
		btnBorrar.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btnBorrar.setBorder(null);
		btnBorrar.setBounds(210, 15, 50, 50);
		panel_1.add(btnBorrar);

		JButton btnDivision = new JButton("");
		btnDivision.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = Float.parseFloat(txtPantalla.getText());
				txtPantalla.setText("");
				operador ="/";
				decimal = false;
			}
		});
		btnDivision.setRolloverIcon(new ImageIcon("src\\imagenes\\btndivision1.png"));
		btnDivision.setIcon(new ImageIcon("src\\imagenes\\btndivision.png"));
		btnDivision.setHorizontalTextPosition(SwingConstants.CENTER);
		btnDivision.setForeground(new Color(30, 30, 30));
		btnDivision.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btnDivision.setBorder(null);
		btnDivision.setBounds(210, 80, 50, 50);
		panel_1.add(btnDivision);

		JButton btnMultiplicacion = new JButton("X");
		btnMultiplicacion.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = Float.parseFloat(txtPantalla.getText());
				txtPantalla.setText("");
				operador ="*";
				decimal = false;
			}
		});
		btnMultiplicacion.setIcon(new ImageIcon("src\\imagenes\\btnazul.png"));
		btnMultiplicacion.setRolloverIcon(new ImageIcon("src\\imagenes\\btnazul1.png"));
		btnMultiplicacion.setHorizontalTextPosition(SwingConstants.CENTER);
		btnMultiplicacion.setForeground(new Color(30, 30, 30));
		btnMultiplicacion.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btnMultiplicacion.setBorder(null);
		btnMultiplicacion.setBounds(210, 145, 50, 50);
		panel_1.add(btnMultiplicacion);

		JButton btnResta = new JButton("−");
		btnResta.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = Float.parseFloat(txtPantalla.getText());
				txtPantalla.setText("");
				operador ="-";
				decimal = false;
			}
		});
		btnResta.setRolloverIcon(new ImageIcon("src\\imagenes\\btnazul1.png"));
		btnResta.setIcon(new ImageIcon("src\\imagenes\\btnazul.png"));
		btnResta.setHorizontalTextPosition(SwingConstants.CENTER);
		btnResta.setForeground(new Color(30, 30, 30));
		btnResta.setFont(new Font("Ebrima", Font.BOLD, 20));
		btnResta.setBorder(null);
		btnResta.setBounds(210, 208, 50, 50);
		panel_1.add(btnResta);

		
		JButton btn7 = new JButton("7");
		btn7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("7");
			}
		});
		btn7.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn7.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn7.setHorizontalTextPosition(SwingConstants.CENTER);
		btn7.setForeground(new Color(30, 30, 30));
		btn7.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn7.setBorder(null);
		btn7.setBounds(15, 145, 50, 50);
		panel_1.add(btn7);

		JButton btn8 = new JButton("8");
		btn8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("8");
			}
		});
		btn8.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn8.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn8.setHorizontalTextPosition(SwingConstants.CENTER);
		btn8.setForeground(new Color(30, 30, 30));
		btn8.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn8.setBorder(null);
		btn8.setBounds(80, 145, 50, 50);
		panel_1.add(btn8);

		JButton btn9 = new JButton("9");
		btn9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("9");
			}
		});
		btn9.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn9.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn9.setHorizontalTextPosition(SwingConstants.CENTER);
		btn9.setForeground(new Color(30, 30, 30));
		btn9.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn9.setBorder(null);
		btn9.setBounds(145, 145, 50, 50);
		panel_1.add(btn9);

		JButton btn4 = new JButton("4");
		btn4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("4");
			}
		});
		btn4.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn4.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn4.setHorizontalTextPosition(SwingConstants.CENTER);
		btn4.setForeground(new Color(30, 30, 30));
		btn4.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn4.setBorder(null);
		btn4.setBounds(15, 208, 50, 50);
		panel_1.add(btn4);

		JButton btn5 = new JButton("5");
		btn5.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn5.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("5");
			}
		});
		btn5.setHorizontalTextPosition(SwingConstants.CENTER);
		btn5.setForeground(new Color(30, 30, 30));
		btn5.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn5.setBorder(null);
		btn5.setBounds(80, 208, 50, 50);
		panel_1.add(btn5);

		JButton btn6 = new JButton("6");
		btn6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("6");
			}
		});
		btn6.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn6.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn6.setHorizontalTextPosition(SwingConstants.CENTER);
		btn6.setForeground(new Color(30, 30, 30));
		btn6.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn6.setBorder(null);
		btn6.setBounds(145, 208, 50, 50);
		panel_1.add(btn6);

		JButton btn1 = new JButton("1");
		btn1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("1");
			}
		});
		btn1.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn1.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn1.setHorizontalTextPosition(SwingConstants.CENTER);
		btn1.setForeground(new Color(30, 30, 30));
		btn1.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn1.setBorder(null);
		btn1.setBounds(15, 275, 50, 50);
		panel_1.add(btn1);

		JButton btn2 = new JButton("2");
		btn2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("2");
			}
		});
		btn2.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn2.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn2.setHorizontalTextPosition(SwingConstants.CENTER);
		btn2.setForeground(new Color(30, 30, 30));
		btn2.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn2.setBorder(null);
		btn2.setBounds(80, 275, 50, 50);
		panel_1.add(btn2);

		JButton btn3 = new JButton("3");
		btn3.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn3.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("3");
			}
		});
		btn3.setHorizontalTextPosition(SwingConstants.CENTER);
		btn3.setForeground(new Color(30, 30, 30));
		btn3.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn3.setBorder(null);
		btn3.setBounds(145, 275, 50, 50);
		panel_1.add(btn3);

		JButton btn = new JButton("");
		btn.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btn.setHorizontalTextPosition(SwingConstants.CENTER);
		btn.setForeground(new Color(30, 30, 30));
		btn.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn.setBorder(null);
		btn.setBounds(15, 340, 50, 50);
		panel_1.add(btn);

		JButton btn0 = new JButton("0");
		btn0.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btn0.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btn0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addNumber("0");
			}
		});
		btn0.setHorizontalTextPosition(SwingConstants.CENTER);
		btn0.setForeground(new Color(30, 30, 30));
		btn0.setFont(new Font("Ebrima", Font.PLAIN, 20));
		btn0.setBorder(null);
		btn0.setBounds(80, 340, 50, 50);
		panel_1.add(btn0);

		JButton btnPunto = new JButton(".");
		btnPunto.setIcon(new ImageIcon("src\\imagenes\\btn.png"));
		btnPunto.setRolloverIcon(new ImageIcon("src\\imagenes\\btn1.png"));
		btnPunto.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(decimal == false) {
					addNumber(".");
					decimal = true;
				}
			}
		});
		btnPunto.setHorizontalTextPosition(SwingConstants.CENTER);
		btnPunto.setForeground(new Color(30, 30, 30));
		btnPunto.setFont(new Font("Ebrima", Font.BOLD, 20));
		btnPunto.setBorder(null);
		btnPunto.setBounds(145, 340, 50, 50);
		panel_1.add(btnPunto);

		JButton btnSuma = new JButton("+");
		btnSuma.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = Float.parseFloat(txtPantalla.getText());
				txtPantalla.setText("");
				operador ="+";
				decimal = false;
			}
		});
		btnSuma.setIcon(new ImageIcon("src\\imagenes\\btnazul.png"));
		btnSuma.setRolloverIcon(new ImageIcon("src\\imagenes\\btnazul1.png"));
		btnSuma.setHorizontalTextPosition(SwingConstants.CENTER);
		btnSuma.setForeground(new Color(30, 30, 30));
		btnSuma.setFont(new Font("Ebrima", Font.BOLD, 20));
		btnSuma.setBorder(null);
		btnSuma.setBounds(210, 275, 50, 50);
		panel_1.add(btnSuma);

		JButton btnPotencia = new JButton("^");
		btnPotencia.setFont(new Font("Ebrima", Font.PLAIN, 25));
		btnPotencia.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = Float.parseFloat(txtPantalla.getText());
				txtPantalla.setText("");
				operador ="^";
				decimal = false;
			}
		});
		btnPotencia.setBorder(null);
		btnPotencia.setHorizontalTextPosition(SwingConstants.CENTER);
		btnPotencia.setRolloverIcon(new ImageIcon("src\\imagenes\\btnx1.png"));
		btnPotencia.setIcon(new ImageIcon("src\\imagenes\\btnx.png"));
		btnPotencia.setBounds(15, 80, 50, 50);
		panel_1.add(btnPotencia);

		JButton btnRaiz = new JButton("√");
		btnRaiz.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				num1 = Float.parseFloat(txtPantalla.getText());
				txtPantalla.setText("");
				operador ="√";
				decimal = false;
			}
		});
		btnRaiz.setFont(new Font("Ebrima", Font.PLAIN, 25));
		btnRaiz.setBorder(null);
		btnRaiz.setRolloverIcon(new ImageIcon("src\\imagenes\\btnx1.png"));
		btnRaiz.setIcon(new ImageIcon("src\\imagenes\\btnx.png"));
		btnRaiz.setHorizontalTextPosition(SwingConstants.CENTER);
		btnRaiz.setBounds(80, 80, 50, 50);
		panel_1.add(btnRaiz);

		JButton btnNewButton_2_2 = new JButton("");
		btnNewButton_2_2.setBorder(null);
		btnNewButton_2_2.setIcon(new ImageIcon("src\\imagenes\\btnx.png"));
		btnNewButton_2_2.setRolloverIcon(new ImageIcon("src\\imagenes\\btnx1.png"));
		btnNewButton_2_2.setHorizontalTextPosition(SwingConstants.CENTER);
		btnNewButton_2_2.setBounds(145, 80, 50, 50);
		panel_1.add(btnNewButton_2_2);
		
		
		JButton btnIgual = new JButton("=");
		btnIgual.setRolloverIcon(new ImageIcon("src\\imagenes\\btnazul1.png"));
		btnIgual.setIcon(new ImageIcon("src\\imagenes\\btnazul.png"));
		btnIgual.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String seleccionar;
				num2 = Float.parseFloat(txtPantalla.getText());
				
				if(operador == "+") {
					resultado = num1 + num2;
					seleccionar = String.format("%.2f", resultado);
					txtPantalla.setText(seleccionar);
				}else if(operador == "-") {
					resultado = num1 - num2;
					seleccionar = String.format("%.2f", resultado);
					txtPantalla.setText(seleccionar);
				}else if(operador == "/") {
					resultado = num1 / num2;
					seleccionar = String.format("%.2f", resultado);
					txtPantalla.setText(seleccionar);
				}else if(operador == "%") {
					resultado = (num1/100)* num2;
					seleccionar = String.format("%.2f", resultado);
					txtPantalla.setText(seleccionar);
				}else if(operador == "*") {
					resultado = num1 * num2;
					seleccionar = String.format("%.2f", resultado);
					txtPantalla.setText(seleccionar);
				}else if(operador == "^") {
					resultado = Math.pow( num1, num2);
					seleccionar = String.format("%.2f", resultado);
					txtPantalla.setText(seleccionar);
				}
				else if(operador == "√") {
					resultado = Math.pow( num2, 1/num1);
					seleccionar = String.format("%.2f", resultado);
					txtPantalla.setText(seleccionar);
				}
			}
		});
		btnIgual.setHorizontalTextPosition(SwingConstants.CENTER);
		btnIgual.setForeground(new Color(30, 30, 30));
		btnIgual.setFont(new Font("Ebrima", Font.BOLD, 20));
		btnIgual.setBorder(null);
		btnIgual.setBounds(210, 340, 50, 50);
		panel_1.add(btnIgual);

	}
}
