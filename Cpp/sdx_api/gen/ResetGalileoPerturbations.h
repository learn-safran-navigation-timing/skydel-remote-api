#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ResetGalileoPerturbations is deprecated since 21.3. You may use ResetPerturbations.
    /// 
    /// Set Galileo orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero
    ///
    /// Name Type Description
    /// ---- ---- -------------------------------------------------------------------------
    /// Prn  int  Satellite PRN number 1..36, or use 0 to apply new value to all satellites
    ///

    class ResetGalileoPerturbations;
    typedef std::shared_ptr<ResetGalileoPerturbations> ResetGalileoPerturbationsPtr;
    
    
    class ResetGalileoPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetGalileoPerturbations();

      ResetGalileoPerturbations(int prn);
  
      static ResetGalileoPerturbationsPtr create(int prn);
      static ResetGalileoPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

