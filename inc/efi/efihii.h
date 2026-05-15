#include "efiprot.h"
#include <stddef.h>
#ifndef EFI_EFIHHI_H_


#define EFI_HII_FONT_PROTOCOL_GUID \
    { 0xe9ca4775, 0x8657, 0x47fc, {0x97, 0xe7, 0x7e, 0xd6, 0x5a, 0x8, 0x43, 0x24 } }

INTERFACE_DECL(_EFI_HII_FONT_PROTOCOL);

typedef UINT32 EFI_HII_OUT_FLAGS;

#define EFI_HII_OUT_FLAG_CLIP             0x00000001
#define EFI_HII_OUT_FLAG_WRAP             0x00000002
#define EFI_HII_OUT_FLAG_CLIP_CLEAN_Y     0x00000004
#define EFI_HII_OUT_FLAG_CLIP_CLEAN_X     0x00000008
#define EFI_HII_OUT_FLAG_TRANSPARENT      0x00000010
#define EFI_HII_IGNORE_IF_NO_GLYPH        0x00000020
#define EFI_HII_IGNORE_LINE_BREAK         0x00000040
#define EFI_HII_DIRECT_TO_SCREEN          0x00000080

typedef CHAR16 *EFI_STRING;

typedef UINT32 EFI_FONT_INFO_MASK;

typedef struct {
  UINTN                                   StartIndex;
  UINTN                                   EndIndex;
  UINTN                                   LineHeight;
  UINTN                                   LineWidth;
  UINTN                                   BaselineOffset;
} EFI_HII_ROW_INFO;


#define EFI_FONT_INFO_SYS_FONT         0x00000001
#define EFI_FONT_INFO_SYS_SIZE         0x00000002
#define EFI_FONT_INFO_SYS_STYLE        0x00000004
#define EFI_FONT_INFO_SYS_FORE_COLOR   0x00000010
#define EFI_FONT_INFO_SYS_BACK_COLOR   0x00000020
#define EFI_FONT_INFO_RESIZE           0x00001000
#define EFI_FONT_INFO_RESTYLE          0x00002000
#define EFI_FONT_INFO_ANY_FONT         0x00010000
#define EFI_FONT_INFO_ANY_SIZE         0x00020000
#define EFI_FONT_INFO_ANY_STYLE        0x00040000


typedef struct {
  UINT16                               Width;
  UINT16                               Height;
  union {
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL      *Bitmap;
    EFI_GRAPHICS_OUTPUT_PROTOCOL       *Screen;
  } Image;
}  EFI_IMAGE_OUTPUT;

typedef
EFI_STATUS
(EFIAPI *EFI_HII_GET_GLYPH) (
  IN struct _EFI_HII_FONT_PROTOCOL       *This,
  IN CHAR16                            Char,
  IN struct EFI_FONT_DISPLAY_INFO       *StringInfo,
  OUT EFI_IMAGE_OUTPUT                 **Blt,
  OUT UINTN                            *Baseline OPTIONAL;
);

typedef UINT32 EFI_HII_FONT_STYLE;
typedef struct {
  EFI_HII_FONT_STYLE       FontStyle;
  UINT16                   FontSize;
  CHAR16                   FontName;
} EFI_FONT_INFO;

typedef struct {
  EFI_GRAPHICS_OUTPUT_BLT_PIXEL                 ForegroundColor;
  EFI_GRAPHICS_OUTPUT_BLT_PIXEL                 BackgroundColor;
  EFI_FONT_INFO_MASK                            FontInfoMask;
  EFI_FONT_INFO                                 FontInfo;
} EFI_FONT_DISPLAY_INFO;

typedef VOID *EFI_FONT_HANDLE;
typedef
EFI_STATUS
(EFIAPI *EFI_HII_GET_FONT_INFO) (
  IN    struct _EFI_HII_FONT_PROTOCOL          *This,
  IN  OUT EFI_FONT_HANDLE                    *FontHandle,
  IN    CONST EFI_FONT_DISPLAY_INFO          *StringInfoIn,OPTIONAL
  OUT   EFI_FONT_DISPLAY_INFO                **StringInfoOut,
  IN    CONST EFI_STRING                     String OPTIONAL
);

typedef UINT16 EFI_STRING_ID;
typedef void *EFI_HII_HANDLE;

typedef
EFI_STATUS
(EFIAPI *EFI_HII_STRING_ID_TO_IMAGE) (
  IN   struct _EFI_HII_FONT_PROTOCOL          *This,
  IN   EFI_HII_OUT_FLAGS                    Flags,
  IN   EFI_HII_HANDLE                       PackageList,
  IN   EFI_STRING_ID                        StringId,
  IN   CONST CHAR8*                         Language,
  IN   CONST EFI_FONT_DISPLAY_INFO          *StringInfo OPTIONAL,
  IN  OUT EFI_IMAGE_OUTPUT                  **Blt,
  IN   UINTN                                BltX,
  IN   UINTN                                BltY,
  OUT   EFI_HII_ROW_INFO                    **RowInfoArray OPTIONAL,
  OUT   UINTN                               *RowInfoArraySize OPTIONAL,
  OUT   UINTN                               *ColumnInfoArray OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_STRING_TO_IMAGE) (
  IN struct _EFI_HII_FONT_PROTOCOL       *This,
  IN EFI_HII_OUT_FLAGS                 Flags,
  IN CONST EFI_STRING                  String,
  IN CONST EFI_FONT_DISPLAY_INFO       *StringInfo OPTIONAL,
  IN OUT EFI_IMAGE_OUTPUT              **Blt,
  IN UINTN                             BltX,
  IN UINTN                             BltY,
  OUT EFI_HII_ROW_INFO                 **RowInfoArray OPTIONAL,
  OUT UINTN                            *RowInfoArraySize OPTIONAL,
  OUT UINTN                            *ColumnInfoArray OPTIONAL
);

typedef struct _EFI_HII_FONT_PROTOCOL {
  EFI_HII_STRING_TO_IMAGE           StringToImage;
  EFI_HII_STRING_ID_TO_IMAGE        StringIdToImage;
  EFI_HII_GET_GLYPH                 GetGlyph;
  EFI_HII_GET_FONT_INFO             GetFontInfo;
} EFI_HII_FONT_PROTOCOL;

typedef struct _EFI_HII_FONT_PROTOCOL _EFI_HII_FONT;
typedef EFI_HII_FONT_PROTOCOL EFI_HII_FONT;

#endif
