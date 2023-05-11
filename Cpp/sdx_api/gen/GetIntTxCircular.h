#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get interference transmitter circular trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxCircular;
    typedef std::shared_ptr<GetIntTxCircular> GetIntTxCircularPtr;
    
    
    class GetIntTxCircular : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxCircular();

      GetIntTxCircular(const std::string& id);

      static GetIntTxCircularPtr create(const std::string& id);
      static GetIntTxCircularPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

