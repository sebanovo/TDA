object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 789
  ClientWidth = 1093
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Image1: TImage
    Left = 203
    Top = 480
    Width = 101
    Height = 89
  end
  object Button1: TButton
    Left = 16
    Top = 8
    Width = 153
    Height = 49
    Caption = 'Crear memoria'
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
    Top = 63
    Width = 153
    Height = 49
    Caption = 'Pedir espacio'
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
    Top = 118
    Width = 153
    Height = 49
    Caption = 'LIberar espacio'
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
    Left = 16
    Top = 173
    Width = 153
    Height = 49
    Caption = 'Mostrar memoria'
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
    Top = 228
    Width = 153
    Height = 49
    Caption = 'Poner dato'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 183
    Top = 72
    Width = 217
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 183
    Top = 127
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object Edit3: TEdit
    Left = 183
    Top = 182
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    Text = '0'
    TextHint = 'a'
  end
  object Edit4: TEdit
    Left = 310
    Top = 182
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    Text = '11'
    TextHint = 'b'
  end
  object Edit5: TEdit
    Left = 183
    Top = 237
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
  end
  object Edit6: TEdit
    Left = 310
    Top = 237
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    Text = '->'
  end
  object Edit7: TEdit
    Left = 437
    Top = 237
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    Text = '1'
  end
  object Button6: TButton
    Left = 16
    Top = 299
    Width = 153
    Height = 49
    Caption = 'Crear lista'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 16
    Top = 354
    Width = 153
    Height = 49
    Caption = 'Insertar primero'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 16
    Top = 409
    Width = 153
    Height = 49
    Caption = 'Insertar '#250'ltimo'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 16
    Top = 464
    Width = 153
    Height = 49
    Caption = 'Mostrar lista'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = Button9Click
  end
  object Edit8: TEdit
    Left = 183
    Top = 363
    Width = 217
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 16
  end
  object Edit9: TEdit
    Left = 183
    Top = 418
    Width = 217
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 17
  end
  object Button10: TButton
    Left = 16
    Top = 543
    Width = 153
    Height = 49
    Caption = 'Crear polinomio'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 18
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 16
    Top = 598
    Width = 153
    Height = 49
    Caption = 'Poner termino'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 19
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 16
    Top = 653
    Width = 153
    Height = 49
    Caption = 'Mostrar polinomio'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 20
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 16
    Top = 708
    Width = 153
    Height = 49
    Caption = 'Derivar'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 21
    OnClick = Button13Click
  end
  object Edit10: TEdit
    Left = 183
    Top = 607
    Width = 106
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 22
  end
  object Edit11: TEdit
    Left = 295
    Top = 607
    Width = 105
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 23
  end
end
