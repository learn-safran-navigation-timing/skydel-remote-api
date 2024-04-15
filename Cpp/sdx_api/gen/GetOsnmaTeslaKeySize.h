#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get OSNMA TESLA key size.
    ///
    /// 
    ///

    class GetOsnmaTeslaKeySize;
    typedef std::shared_ptr<GetOsnmaTeslaKeySize> GetOsnmaTeslaKeySizePtr;
    
    
    class GetOsnmaTeslaKeySize : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaTeslaKeySize();

      static GetOsnmaTeslaKeySizePtr create();
      static GetOsnmaTeslaKeySizePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

