HEADER = [
    {'name':'toh',                'range':[0,11]},
    {'name':'mask_flag',          'range':[12,12]},
    {'name':'orbit_corr_flag',    'range':[13,13]},
    {'name':'clock_fullset_flag', 'range':[14,14]},
    {'name':'clock_subset_flag',  'range':[15,15]},
    {'name':'code_bias_flag',     'range':[16,16]},
    {'name':'phase_bias_flag',    'range':[17,17]},
    {'name':'reserved',           'range':[18,21]},
    {'name':'mask_id',            'range':[22,26]},
    {'name':'iod_set_id',         'range':[27,31]}]

def header(msg):
    return {'header': 
            {'toh':                msg['toh']['decimal'],                
             'mask_flag':          int(msg['mask_flag']['decimal']) == 1,          
             'orbit_corr_flag':    int(msg['orbit_corr_flag']['decimal']) == 1,    
             'clock_fullset_flag': int(msg['clock_fullset_flag']['decimal']) == 1, 
             'clock_subset_flag':  int(msg['clock_subset_flag']['decimal']) == 1,  
             'code_bias_flag':     int(msg['code_bias_flag']['decimal']) == 1,     
             'phase_bias_flag':    int(msg['phase_bias_flag']['decimal']) == 1,    
             'reserved':           msg['reserved']['decimal'],           
             'mask_id':            msg['mask_id']['decimal'],            
             'iod_set_id':         msg['iod_set_id']['decimal']}
            }