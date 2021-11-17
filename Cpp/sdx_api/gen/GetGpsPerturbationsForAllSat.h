#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsPerturbationsForAllSat is deprecated since 21.3. You may use GetPerturbationsForAllSat.
    /// 
    /// Get GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.
    /// All parameters are zero based index (index 0 => PRN 1, index 1 => PRN 2, etc)
    ///
    /// 
    ///

    class GetGpsPerturbationsForAllSat;
    typedef std::shared_ptr<GetGpsPerturbationsForAllSat> GetGpsPerturbationsForAllSatPtr;
    
    
    class GetGpsPerturbationsForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsPerturbationsForAllSat();
  
      static GetGpsPerturbationsForAllSatPtr create();
      static GetGpsPerturbationsForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

