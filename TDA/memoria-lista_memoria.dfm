object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 696
  ClientWidth = 1087
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 24
    Top = 48
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
    Left = 24
    Top = 103
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
    Left = 24
    Top = 158
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
    Left = 24
    Top = 213
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
    Left = 24
    Top = 268
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
    Left = 191
    Top = 112
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
    Left = 191
    Top = 167
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
    Left = 191
    Top = 222
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
    Left = 318
    Top = 222
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
    Left = 191
    Top = 277
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
    Left = 318
    Top = 277
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
    Left = 445
    Top = 277
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
    Left = 24
    Top = 339
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
    Left = 24
    Top = 394
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
    Left = 24
    Top = 449
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
    Left = 24
    Top = 504
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
    Left = 191
    Top = 403
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
    Left = 191
    Top = 458
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
end
