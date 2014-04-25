//
//  S2LNewResultViewController.h
//  snap2life suite
//
//  Created by Antonio_Stilo on 11/21/13.
//  Copyright (c) 2013 Prisma Gmbh. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ObjectDef.h"
#import "History.h"
#import "S2LCommunitySnapDef.h"
#import "ADPopupView.h"
#import "S2LCommentPopoView.h"
#import "S2LShearPopView.h"

@interface S2LNewResultViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UINavigationBarDelegate>
{
    IBOutlet UIScrollView* scroll;
    IBOutlet UILabel* titleLabel;
    IBOutlet UILabel* descriptionLabel;
    IBOutlet UIImageView* background;
    IBOutlet UITableView* table;
    
    NSArray *features;
    NSString *snapID;
    
    BOOL isFirst;
    
    ADPopupView *shearPopUP;
    ADPopupView *commentPopUP;
    
}

//@property (nonatomic, unsafe_unretained) IBOutlet id<WebViewDelegate> delegate;

@property (nonatomic) int index;
@property (nonatomic, strong)ObjectDef* object;
@property (nonatomic, strong)History* history;
@property (nonatomic) IBOutlet UIButton *commentBtn;
@property (nonatomic) IBOutlet UIButton *shearBtn;


@end
