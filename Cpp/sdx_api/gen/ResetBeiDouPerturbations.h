#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ResetBeiDouPerturbations is deprecated since 21.3. You may use ResetPerturbations.
    /// 
    /// Set BeiDou orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero
    ///
    /// Name Type Description
    /// ---- ---- -------------------------------------------------------------------------
    /// Prn  int  Satellite PRN number 1..30, or use 0 to apply new value to all satellites
    ///

    class ResetBeiDouPerturbations;
    typedef std::shared_ptr<ResetBeiDouPerturbations> ResetBeiDouPerturbationsPtr;
    
    
    class ResetBeiDouPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetBeiDouPerturbations();

      ResetBeiDouPerturbations(int prn);
  
      static ResetBeiDouPerturbationsPtr create(int prn);
      static ResetBeiDouPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

