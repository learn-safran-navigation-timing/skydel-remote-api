#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouPerturbations is deprecated since 21.3. You may use GetPerturbations.
    /// 
    /// Get BeiDou orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..30
    ///

    class GetBeiDouPerturbations;
    typedef std::shared_ptr<GetBeiDouPerturbations> GetBeiDouPerturbationsPtr;
    
    
    class GetBeiDouPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouPerturbations();

      GetBeiDouPerturbations(int prn);
  
      static GetBeiDouPerturbationsPtr create(int prn);
      static GetBeiDouPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

