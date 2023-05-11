#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get an antenna change.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetAntennaChange;
    typedef std::shared_ptr<GetAntennaChange> GetAntennaChangePtr;
    
    
    class GetAntennaChange : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAntennaChange();

      GetAntennaChange(const std::string& id);

      static GetAntennaChangePtr create(const std::string& id);
      static GetAntennaChangePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

