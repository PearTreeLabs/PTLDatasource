//
//  PTLTableViewUpdateManager.h
//  PTLDatasource
//
//  Created by Brian Partridge on 8/2/14.
//
//

#import <UIKit/UIKit.h>
#import "PTLDatasource.h"

// Manages datasource updates and animates changes to a UITableView.
@interface PTLTableViewUpdateManager : NSObject <PTLDatasourceObserver>

@property (nonatomic, weak, readonly) UITableView *tableView;

- (instancetype)initWithTableView:(UITableView *)tableView;

@end
