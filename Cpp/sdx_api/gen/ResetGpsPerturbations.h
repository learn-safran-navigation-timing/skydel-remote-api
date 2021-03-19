#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ResetGpsPerturbations is deprecated since 21.3. You may use ResetPerturbations.
    /// 
    /// Set GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero
    ///
    /// Name Type Description
    /// ---- ---- -------------------------------------------------------------------------
    /// Prn  int  Satellite PRN number 1..32, or use 0 to apply new value to all satellites
    ///

    class ResetGpsPerturbations;
    typedef std::shared_ptr<ResetGpsPerturbations> ResetGpsPerturbationsPtr;
    
    
    class ResetGpsPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetGpsPerturbations();

      ResetGpsPerturbations(int prn);
  
      static ResetGpsPerturbationsPtr create(int prn);
      static ResetGpsPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

