#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class MyOpenGLWidget
    : public QOpenGLWidget
    , protected QOpenGLFunctions
{
    Q_OBJECT

  public:
    MyOpenGLWidget(QWidget *parent);
    ~MyOpenGLWidget();

  protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

  private:
    GLuint createShaderFromFile(GLenum shaderType, const QString &filePath);
    GLuint createShaderFromString(GLenum shaderType, const QString &source);

    GLuint programHandle_;  // プログラムオブジェクトのハンドラ
};

#endif  // MYOPENGLWIDGET_H
