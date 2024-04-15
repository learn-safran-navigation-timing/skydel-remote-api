#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get spoofer transmitter circular trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxCircular;
    typedef std::shared_ptr<GetSpoofTxCircular> GetSpoofTxCircularPtr;
    
    
    class GetSpoofTxCircular : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofTxCircular();

      GetSpoofTxCircular(const std::string& id);

      static GetSpoofTxCircularPtr create(const std::string& id);
      static GetSpoofTxCircularPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

