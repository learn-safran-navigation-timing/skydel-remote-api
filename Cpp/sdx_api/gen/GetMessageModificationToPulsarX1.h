#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the PULSAR X1 message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToPulsarX1;
    typedef std::shared_ptr<GetMessageModificationToPulsarX1> GetMessageModificationToPulsarX1Ptr;
    
    
    class GetMessageModificationToPulsarX1 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToPulsarX1();

      GetMessageModificationToPulsarX1(const std::string& id);

      static GetMessageModificationToPulsarX1Ptr create(const std::string& id);
      static GetMessageModificationToPulsarX1Ptr dynamicCast(CommandBasePtr ptr);
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

