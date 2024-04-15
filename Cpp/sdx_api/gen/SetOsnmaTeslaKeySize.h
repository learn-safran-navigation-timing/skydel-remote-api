#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA TESLA key size.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------
    /// KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.
    ///              Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.
    ///

    class SetOsnmaTeslaKeySize;
    typedef std::shared_ptr<SetOsnmaTeslaKeySize> SetOsnmaTeslaKeySizePtr;
    
    
    class SetOsnmaTeslaKeySize : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetOsnmaTeslaKeySize();

      SetOsnmaTeslaKeySize(int keySize);

      static SetOsnmaTeslaKeySizePtr create(int keySize);
      static SetOsnmaTeslaKeySizePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** keySize ****
      int keySize() const;
      void setKeySize(int keySize);
    };
    
  }
}

