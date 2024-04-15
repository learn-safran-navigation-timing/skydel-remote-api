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

    class GetIntTxAntenna;
    typedef std::shared_ptr<GetIntTxAntenna> GetIntTxAntennaPtr;
    
    
    class GetIntTxAntenna : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxAntenna();

      GetIntTxAntenna(const std::string& id);

      static GetIntTxAntennaPtr create(const std::string& id);
      static GetIntTxAntennaPtr dynamicCast(CommandBasePtr ptr);
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

