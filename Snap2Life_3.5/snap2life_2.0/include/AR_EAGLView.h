/*==============================================================================
 Copyright (c) 2010-2013 QUALCOMM Austria Research Center GmbH.
 All Rights Reserved.
 Qualcomm Confidential and Proprietary
 ==============================================================================*/

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import "UIGLViewProtocol.h"
#include "EPLShared.h"
#import "AR_ContextManager.h"

@class Texture;

// structure to point to an object to be drawn
@interface Object3D : NSObject {
    unsigned int numVertices;
    const float *vertices;
    const float *normals;
    const float *texCoords;
    
    unsigned int numIndices;
    const unsigned short *indices;
}

@property (nonatomic) unsigned int numVertices;
@property (nonatomic) const float *vertices;
@property (nonatomic) const float *normals;
@property (nonatomic) const float *texCoords;
@property (nonatomic) unsigned int numIndices;
@property (nonatomic) const unsigned short *indices;
@property (nonatomic, unsafe_unretained) Texture *texture;
@property (nonatomic,retain) NSArray *buttons;
@property (nonatomic,copy) NSString *name;

@end


@class QCARutils;

// This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView
// subclass.  The view content is basically an EAGL surface you render your
// OpenGL scene into.  Note that setting the view non-opaque will only work if
// the EAGL surface has an alpha channel.
@interface AR_EAGLView : UIView <UIGLViewProtocol>

{
@public
    NSMutableArray *textureList; // list of textures to load
    CGPoint touchLocation;
    BOOL isTap;
    
@protected
    QCARutils *qUtils; // QCAR utils class
    
    EAGLContext *context;
    
    //Elbe Player///////////
    //int _viewHandle;
    //int _adHandle;
    
    NSString    *_wz5File;
    NSString    *_packFile;
    NSString    *_packFileOld;

    //////////////////////
    
    
    // The pixel dimensions of the CAEAGLLayer.
    GLint framebufferWidth;
    GLint framebufferHeight;
    
    // The OpenGL ES names for the framebuffer and renderbuffers used to render
    // to this view.
    GLuint defaultFramebuffer;
    GLuint colorRenderbuffer;
    GLuint depthRenderbuffer;
    
    NSMutableArray* textures;   // loaded textures
    //NSMutableArray *objects3D;  // objects to draw
    BOOL renderingInited;
    
#ifndef USE_OPENGL1
    // *** Note, OpenGL ES 1.x is supported only in the ImageTargets sample ***
    // OpenGL 2 data
    GLuint shaderProgramID;
    GLint vertexHandle;
    GLint normalHandle;
    GLint textureCoordHandle;
    GLint mvpMatrixHandle;
    GLint texSampler2DHandle;
#endif
}

@property (nonatomic, retain) NSMutableArray *objects3D;
@property (nonatomic, retain) NSMutableArray *textureList;

- (void) useTextures:(NSMutableArray *)theTextures;

// OpenGL ES clean up when going into the background
- (void)finishOpenGLESCommands;
- (void)freeOpenGLESResources;

// for overriding in the EAGLView subclass
- (void)setFramebuffer;
- (BOOL)presentFramebuffer;
- (void)createFramebuffer;
- (void)deleteFramebuffer;
- (void)initRendering;
- (void)initShaders;

@end
