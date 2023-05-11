#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a transmitter color in spectrums
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxColor;
    typedef std::shared_ptr<GetIntTxColor> GetIntTxColorPtr;
    
    
    class GetIntTxColor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxColor();

      GetIntTxColor(const std::string& id);

      static GetIntTxColorPtr create(const std::string& id);
      static GetIntTxColorPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

