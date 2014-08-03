//
//  PTLTableViewUpdateManager.m
//  PTLDatasource
//
//  Created by Brian Partridge on 8/2/14.
//
//

#import "PTLTableViewUpdateManager.h"
#import "UITableView+PTLDatasource.h"

@interface PTLTableViewUpdateManager ()

@property (nonatomic, weak, readwrite) UITableView *tableView;

@end

@implementation PTLTableViewUpdateManager

- (instancetype)initWithTableView:(UITableView *)tableView {
	self = [super init];
	if (!self) {
        return nil;
	}
    
    _tableView = tableView;
    [_tableView.ptl_datasource addChangeObserver:self];
    
	return self;
}

#pragma mark - PTLDatasourceObserver

- (void)datasourceWillChange:(id<PTLDatasource>)datasource {
    [self.tableView beginUpdates];
}

- (void)datasourceDidChange:(id<PTLDatasource>)datasource {
    [self.tableView endUpdates];
}

- (void)datasource:(id<PTLDatasource>)datasource didChange:(PTLChangeType)change atIndexPath:(NSIndexPath *)indexPath newIndexPath:(NSIndexPath *)newIndexPath {
    switch(change) {
        case PTLChangeTypeInsert:
            [self.tableView insertRowsAtIndexPaths:@[newIndexPath]
                                  withRowAnimation:UITableViewRowAnimationAutomatic];
            break;
            
        case PTLChangeTypeRemove:
            [self.tableView deleteRowsAtIndexPaths:@[indexPath]
                                  withRowAnimation:UITableViewRowAnimationAutomatic];
            break;
            
        case PTLChangeTypeUpdate:
            // As suggested by oleb: http://oleb.net/blog/2013/02/nsfetchedresultscontroller-documentation-bug/
            [self.tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
            break;
            
        case PTLChangeTypeMove:
            [self.tableView deleteRowsAtIndexPaths:@[indexPath]
                                  withRowAnimation:UITableViewRowAnimationAutomatic];
            [self.tableView insertRowsAtIndexPaths:@[newIndexPath]
                                  withRowAnimation:UITableViewRowAnimationAutomatic];
            break;
    }
}

- (void)datasource:(id<PTLDatasource>)datasource didChange:(PTLChangeType)change atSectionIndex:(NSInteger)sectionIndex {
    switch(change) {
        case PTLChangeTypeInsert:
            [self.tableView insertSections:[NSIndexSet indexSetWithIndex:sectionIndex]
                          withRowAnimation:UITableViewRowAnimationAutomatic];
            break;
            
        case PTLChangeTypeRemove:
            [self.tableView deleteSections:[NSIndexSet indexSetWithIndex:sectionIndex]
                          withRowAnimation:UITableViewRowAnimationAutomatic];
            break;
        default:
            break;
    }
}

@end
