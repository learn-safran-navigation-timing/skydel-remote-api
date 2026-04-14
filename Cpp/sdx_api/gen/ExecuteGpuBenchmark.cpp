
#include "ExecuteGpuBenchmark.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExecuteGpuBenchmark
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExecuteGpuBenchmark::CmdName = "ExecuteGpuBenchmark";
    const char* const ExecuteGpuBenchmark::Documentation = "Execute the GPU benchmark and get the result score (will block Skydel's user interface).\n"
      "\n"
      "Name                            Type                     Description\n"
      "------------------------------- ------------------------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "DurationMs                      int                      Duration of execution in milliseconds.\n"
      "SystemSvCountDict               dict string:int          A dictionary of system svcount pairs.\n"
      "                                                         Accepted keys are: \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\" and\n"
      "                                                                            \"NavIC\"\n"
      "EchoCount                       int                      Number of echos per signal.\n"
      "InterferenceSignalTypeCountDict optional dict string:int Optional dictionary defining the interference signals to benchmark. Keys are interference signal types (\"CW\", \"Chirp\", \"Pulse\", \"BPSK\", \"BOC\", \"AWGN\"), and values specify how many of each type to include.";
    const char* const ExecuteGpuBenchmark::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExecuteGpuBenchmark);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExecuteGpuBenchmark);


    ExecuteGpuBenchmark::ExecuteGpuBenchmark()
      : CommandBase(CmdName, TargetId)
    {}

    ExecuteGpuBenchmark::ExecuteGpuBenchmark(int durationMs, const std::map<std::string, int>& systemSvCountDict, int echoCount, const std::optional<std::map<std::string, int>>& interferenceSignalTypeCountDict)
      : CommandBase(CmdName, TargetId)
    {

      setDurationMs(durationMs);
      setSystemSvCountDict(systemSvCountDict);
      setEchoCount(echoCount);
      setInterferenceSignalTypeCountDict(interferenceSignalTypeCountDict);
    }

    ExecuteGpuBenchmarkPtr ExecuteGpuBenchmark::create(int durationMs, const std::map<std::string, int>& systemSvCountDict, int echoCount, const std::optional<std::map<std::string, int>>& interferenceSignalTypeCountDict)
    {
      return std::make_shared<ExecuteGpuBenchmark>(durationMs, systemSvCountDict, echoCount, interferenceSignalTypeCountDict);
    }

    ExecuteGpuBenchmarkPtr ExecuteGpuBenchmark::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExecuteGpuBenchmark>(ptr);
    }

    bool ExecuteGpuBenchmark::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["DurationMs"])
          && parse_json<std::map<std::string, int>>::is_valid(m_values["SystemSvCountDict"])
          && parse_json<int>::is_valid(m_values["EchoCount"])
          && parse_json<std::optional<std::map<std::string, int>>>::is_valid(m_values["InterferenceSignalTypeCountDict"])
        ;

    }

    std::string ExecuteGpuBenchmark::documentation() const { return Documentation; }

    const std::vector<std::string>& ExecuteGpuBenchmark::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DurationMs", "SystemSvCountDict", "EchoCount", "InterferenceSignalTypeCountDict"}; 
      return names; 
    }


    int ExecuteGpuBenchmark::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ExecuteGpuBenchmark::durationMs() const
    {
      return parse_json<int>::parse(m_values["DurationMs"]);
    }

    void ExecuteGpuBenchmark::setDurationMs(int durationMs)
    {
      setValue("DurationMs", parse_json<int>::format(durationMs, m_values.GetAllocator()));
    }



    std::map<std::string, int> ExecuteGpuBenchmark::systemSvCountDict() const
    {
      return parse_json<std::map<std::string, int>>::parse(m_values["SystemSvCountDict"]);
    }

    void ExecuteGpuBenchmark::setSystemSvCountDict(const std::map<std::string, int>& systemSvCountDict)
    {
      setValue("SystemSvCountDict", parse_json<std::map<std::string, int>>::format(systemSvCountDict, m_values.GetAllocator()));
    }



    int ExecuteGpuBenchmark::echoCount() const
    {
      return parse_json<int>::parse(m_values["EchoCount"]);
    }

    void ExecuteGpuBenchmark::setEchoCount(int echoCount)
    {
      setValue("EchoCount", parse_json<int>::format(echoCount, m_values.GetAllocator()));
    }



    std::optional<std::map<std::string, int>> ExecuteGpuBenchmark::interferenceSignalTypeCountDict() const
    {
      return parse_json<std::optional<std::map<std::string, int>>>::parse(m_values["InterferenceSignalTypeCountDict"]);
    }

    void ExecuteGpuBenchmark::setInterferenceSignalTypeCountDict(const std::optional<std::map<std::string, int>>& interferenceSignalTypeCountDict)
    {
      setValue("InterferenceSignalTypeCountDict", parse_json<std::optional<std::map<std::string, int>>>::format(interferenceSignalTypeCountDict, m_values.GetAllocator()));
    }


  }
}
