#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsPerturbations is deprecated since 21.3. You may use Perturbations.
    /// 
    /// Get GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsPerturbations;
    typedef std::shared_ptr<GetGpsPerturbations> GetGpsPerturbationsPtr;
    
    
    class GetGpsPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsPerturbations();

      GetGpsPerturbations(int prn);
  
      static GetGpsPerturbationsPtr create(int prn);
      static GetGpsPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

