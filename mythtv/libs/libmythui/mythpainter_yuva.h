#ifndef MYTHPAINTER_YUVA_H_
#define MYTHPAINTER_YUVA_H_

#include "mythpainter_qimage.h"
#include "mythimage.h"
#include "compat.h"

class MythFontProperties;

class MPUBLIC MythYUVAPainter : public MythQImagePainter
{
  public:
    MythYUVAPainter() : MythQImagePainter(), m_fontStretch(100) { }
   ~MythYUVAPainter();

    QString GetName(void) { return QString("YUVA"); }
    void DrawImage(const QRect &dest, MythImage *im, const QRect &src,
                   int alpha);
    void DrawText(const QRect &dest, const QString &msg, int flags,
                  const MythFontProperties &font, int alpha,
                  const QRect &boundRect);
    void DrawRect(const QRect &area, bool drawFill, const QColor &fillColor, 
                  bool drawLine, int lineWidth, const QColor &lineColor);
    void DrawRoundRect(const QRect &area, int radius, 
                       bool drawFill, const QColor &fillColor, 
                       bool drawLine, int lineWidth, const QColor &lineColor);
    void SetFontStretch(int font_stretch) { m_fontStretch = font_stretch; }

  protected:
    MythFontProperties* GetConvertedFont(const MythFontProperties &font);

    QMap<QString, MythFontProperties*> m_convertedFonts;
    std::list<QString> m_expireList;
    int m_fontStretch;
};

#endif
