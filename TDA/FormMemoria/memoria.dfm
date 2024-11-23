object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 522
  ClientWidth = 949
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 32
    Top = 56
    Width = 161
    Height = 58
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
    Left = 32
    Top = 128
    Width = 161
    Height = 58
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
  object Button4: TButton
    Left = 32
    Top = 283
    Width = 161
    Height = 58
    Caption = 'Mostrar memoria'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 32
    Top = 347
    Width = 161
    Height = 58
    Caption = 'Poner dato'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 216
    Top = 141
    Width = 217
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 216
    Top = 220
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object Edit3: TEdit
    Left = 216
    Top = 296
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    Text = '0'
    TextHint = 'a'
  end
  object Edit4: TEdit
    Left = 343
    Top = 296
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    Text = '11'
    TextHint = 'b'
  end
  object Edit5: TEdit
    Left = 216
    Top = 360
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object Edit6: TEdit
    Left = 343
    Top = 360
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    Text = '->'
  end
  object Edit7: TEdit
    Left = 470
    Top = 360
    Width = 121
    Height = 31
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    Text = '1'
  end
  object Button3: TButton
    Left = 32
    Top = 199
    Width = 161
    Height = 65
    Caption = 'Liberar espacio'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = '@Microsoft YaHei UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = Button3Click
  end
end
