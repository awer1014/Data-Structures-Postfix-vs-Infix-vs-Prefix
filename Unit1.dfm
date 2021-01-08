object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 597
  ClientWidth = 717
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 717
    Height = 185
    ActivePage = TabSheet1
    Align = alTop
    TabOrder = 0
    ExplicitTop = -4
    object TabSheet1: TTabSheet
      Caption = 'Infix'
      object Button2: TButton
        Left = 36
        Top = 102
        Width = 75
        Height = 25
        Caption = 'Posfix'
        TabOrder = 0
        OnClick = Button2Click
      end
      object Edit1: TEdit
        Left = 148
        Top = 16
        Width = 501
        Height = 21
        TabOrder = 1
        Text = 'Edit1'
      end
      object Edit2: TEdit
        Left = 148
        Top = 60
        Width = 501
        Height = 21
        TabOrder = 2
        Text = 'Edit2'
      end
      object Edit3: TEdit
        Left = 148
        Top = 104
        Width = 501
        Height = 21
        TabOrder = 3
        Text = 'Edit3'
      end
      object Button1: TButton
        Left = 36
        Top = 58
        Width = 75
        Height = 25
        Caption = 'Prefix'
        TabOrder = 4
        OnClick = Button1Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Prefix'
      ImageIndex = 1
      object Edit4: TEdit
        Left = 148
        Top = 16
        Width = 501
        Height = 21
        TabOrder = 0
        Text = 'Edit4'
      end
      object Edit5: TEdit
        Left = 148
        Top = 60
        Width = 501
        Height = 21
        TabOrder = 1
        Text = 'Edit5'
      end
      object Edit6: TEdit
        Left = 148
        Top = 104
        Width = 501
        Height = 21
        TabOrder = 2
        Text = 'Edit6'
      end
      object Button3: TButton
        Left = 36
        Top = 102
        Width = 75
        Height = 25
        Caption = 'Infix'
        TabOrder = 3
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 36
        Top = 58
        Width = 75
        Height = 25
        Caption = 'Posfix'
        TabOrder = 4
        OnClick = Button4Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Posfix'
      ImageIndex = 2
      object Button5: TButton
        Left = 36
        Top = 58
        Width = 75
        Height = 25
        Caption = 'Prefix'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 36
        Top = 102
        Width = 75
        Height = 25
        Caption = 'Infix'
        TabOrder = 1
        OnClick = Button6Click
      end
      object Edit7: TEdit
        Left = 148
        Top = 16
        Width = 501
        Height = 21
        TabOrder = 2
        Text = 'Edit7'
      end
      object Edit8: TEdit
        Left = 148
        Top = 60
        Width = 501
        Height = 21
        TabOrder = 3
        Text = 'Edit8'
      end
      object Edit9: TEdit
        Left = 148
        Top = 104
        Width = 501
        Height = 21
        TabOrder = 4
        Text = 'Edit9'
      end
    end
  end
  object CheckBox2: TCheckBox
    Left = 143
    Top = 187
    Width = 97
    Height = 17
    Caption = 'Tracing'
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 0
    Top = 204
    Width = 717
    Height = 393
    Align = alBottom
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object CheckBox1: TCheckBox
    Left = 40
    Top = 187
    Width = 97
    Height = 17
    Caption = 'Stack'
    TabOrder = 3
  end
end
