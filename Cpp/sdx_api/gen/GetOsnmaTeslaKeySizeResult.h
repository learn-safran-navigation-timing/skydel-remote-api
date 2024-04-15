#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetOsnmaTeslaKeySize.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------
    /// KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.
    ///              Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.
    ///

    class GetOsnmaTeslaKeySizeResult;
    typedef std::shared_ptr<GetOsnmaTeslaKeySizeResult> GetOsnmaTeslaKeySizeResultPtr;
    
    
    class GetOsnmaTeslaKeySizeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaTeslaKeySizeResult();

      GetOsnmaTeslaKeySizeResult(int keySize);

      GetOsnmaTeslaKeySizeResult(CommandBasePtr relatedCommand, int keySize);

      static GetOsnmaTeslaKeySizeResultPtr create(int keySize);

      static GetOsnmaTeslaKeySizeResultPtr create(CommandBasePtr relatedCommand, int keySize);
      static GetOsnmaTeslaKeySizeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** keySize ****
      int keySize() const;
      void setKeySize(int keySize);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaTeslaKeySizeResult);
  }
}

