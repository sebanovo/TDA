object Form7: TForm7
  Left = 0
  Top = 0
  Caption = 'Form7'
  ClientHeight = 643
  ClientWidth = 1092
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 16
    Top = 63
    Width = 153
    Height = 49
    Caption = 'Crear Conjunto A'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 118
    Width = 153
    Height = 49
    Caption = 'Crear Conjunto B'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 16
    Top = 173
    Width = 153
    Height = 49
    Caption = 'Crear Conjunto C'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 228
    Width = 153
    Height = 49
    Caption = 'Insertar Elemento'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 16
    Top = 283
    Width = 153
    Height = 49
    Caption = 'Mostrar Conjunto'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 16
    Top = 338
    Width = 153
    Height = 49
    Caption = 'Union'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 16
    Top = 393
    Width = 153
    Height = 49
    Caption = 'Interseccion'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 16
    Top = 448
    Width = 153
    Height = 49
    Caption = 'Salir'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object ComboBox1: TComboBox
    Left = 192
    Top = 272
    Width = 97
    Height = 23
    ItemIndex = 0
    TabOrder = 8
    Text = 'A'
    Items.Strings = (
      'A'
      'B'
      'C')
  end
end
