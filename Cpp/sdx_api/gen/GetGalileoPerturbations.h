#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoPerturbations is deprecated since 21.3. You may use GetPerturbations.
    /// 
    /// Get GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..36
    ///

    class GetGalileoPerturbations;
    typedef std::shared_ptr<GetGalileoPerturbations> GetGalileoPerturbationsPtr;
    
    
    class GetGalileoPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoPerturbations();

      GetGalileoPerturbations(int prn);
  
      static GetGalileoPerturbationsPtr create(int prn);
      static GetGalileoPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

