#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Galileo signal health for I/NAV and F/NAV message
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite's SV ID 1..36
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// Health      int             Signal health 0..3
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGalileoSignalHealthForSV;
    typedef std::shared_ptr<SetGalileoSignalHealthForSV> SetGalileoSignalHealthForSVPtr;
    
    
    class SetGalileoSignalHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGalileoSignalHealthForSV();

      SetGalileoSignalHealthForSV(int svId, const std::string& component, int health, const std::optional<std::string>& dataSetName = {});

      static SetGalileoSignalHealthForSVPtr create(int svId, const std::string& component, int health, const std::optional<std::string>& dataSetName = {});
      static SetGalileoSignalHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);


      // **** health ****
      int health() const;
      void setHealth(int health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

