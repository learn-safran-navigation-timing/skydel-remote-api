#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsCodePrn is deprecated since 21.3. You may use GetPrnOfSVID.
    /// 
    /// Get the transmitted PRN code for the specified satellite
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------
    /// SatPrn int  The GPS satellite PRN [1..32]
    ///

    class GetGpsCodePrn;
    typedef std::shared_ptr<GetGpsCodePrn> GetGpsCodePrnPtr;
    
    
    class GetGpsCodePrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCodePrn();

      GetGpsCodePrn(int satPrn);
  
      static GetGpsCodePrnPtr create(int satPrn);
      static GetGpsCodePrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** satPrn ****
      int satPrn() const;
      void setSatPrn(int satPrn);
    };
  }
}

