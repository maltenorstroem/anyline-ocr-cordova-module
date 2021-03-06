
#import <UIKit/UIKit.h>

#import <Anyline/Anyline.h>
#import "ALCordovaUIConfiguration.h"

@protocol AnylineBaseScanViewControllerDelegate;

@interface AnylineBaseScanViewController : UIViewController

@property (nonatomic,strong) UILabel *scannedLabel;

@property (nonatomic, strong) ALUIConfiguration *conf;
@property (nonatomic, strong) AnylineAbstractModuleView *moduleView;
@property (nonatomic, weak) id<AnylineBaseScanViewControllerDelegate> delegate;
@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) ALCordovaUIConfiguration *cordovaConfig;

-(instancetype)initWithKey:(NSString*)key configuration:(ALUIConfiguration *)conf cordovaConfiguration:(ALCordovaUIConfiguration*)cordovaConf delegate:(id<AnylineBaseScanViewControllerDelegate>)delegate;

- (NSString *)saveImageToFileSystem:(UIImage *)image;

- (void)flashResultFor:(NSTimeInterval) duration;


@end

@protocol AnylineBaseScanViewControllerDelegate <NSObject>

@required

- (void)anylineBaseScanViewController:(AnylineBaseScanViewController *)baseScanViewController
                              didScan:(id)scanResult
                     continueScanning:(BOOL)continueScanning;

-(void)anylineBaseScanViewController:(AnylineBaseScanViewController *)baseScanViewController didStopScanning:(id)sender;
@end