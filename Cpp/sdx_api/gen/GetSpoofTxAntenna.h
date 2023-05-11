#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get transmitter antenna pattern.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxAntenna;
    typedef std::shared_ptr<GetSpoofTxAntenna> GetSpoofTxAntennaPtr;
    
    
    class GetSpoofTxAntenna : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxAntenna();

      GetSpoofTxAntenna(const std::string& id);

      static GetSpoofTxAntennaPtr create(const std::string& id);
      static GetSpoofTxAntennaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

